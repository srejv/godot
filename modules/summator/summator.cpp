/* summator.cpp */

#include "summator.h"

int Summator::get_number_of_ports() {
  if (midi_in)
    return midi_in->getPortCount();
  return -1;
}
void Summator::open_port(int value) {
  midi_in->openPort(value);
  midi_in->ignoreTypes( true, true, true );
}
int Summator::get_message() {
  auto stamp = midi_in->getMessage(&message);
  auto nBytes = message.size();
  for (auto i=0; i<nBytes; i++ ) {
    printf("Byte %d = %d", i, (int)message[i]);
  }
  if ( nBytes > 0 ) {
    printf("stamp = %f\n", stamp);
  }
  return nBytes;
}

int Summator::get_message_part(int index) {
  if (message.size() > 0) {
    return (int)message[index];
  }
  return -1;
}

int Summator::init() {
  try {
    midi_in = new RtMidiIn(RtMidi::Api::WINDOWS_MM);
  } catch (RtMidiError &error) {
    error.printMessage();
  }
  if(midi_in) return 1;
  return 0;
}

String Summator::get_midi_name(int index) {
  return String(midi_in->getPortName(index).c_str());
}

void Summator::_bind_methods() {

    ClassDB::bind_method(D_METHOD("get_number_of_ports"), &Summator::get_number_of_ports);
    ClassDB::bind_method(D_METHOD("open_port", "value"), &Summator::open_port);
    ClassDB::bind_method(D_METHOD("get_message"), &Summator::get_message);
    ClassDB::bind_method(D_METHOD("get_message_part", "index"), &Summator::get_message_part);
    ClassDB::bind_method(D_METHOD("get_midi_name", "index"), &Summator::get_midi_name);

    ClassDB::bind_method(D_METHOD("init"), &Summator::init);
}

Summator::Summator() {
}

Summator::~Summator() {
    if(midi_in) {
      delete midi_in;
    }
}
