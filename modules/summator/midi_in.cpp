/* summator.cpp */

#include "midi_in.h"

bool MidiIn::init() {
  try {
    midi_in = new RtMidiIn();
  } catch (RtMidiError &error) {
    error.printMessage();
  }
  if(midi_in) return true;
  return false;
}


int MidiIn::get_number_of_ports() {
  if (midi_in) {
    return midi_in->getPortCount();
  }
  return -1;
}

String MidiIn::get_port_name(int index) {
  if(midi_in) {
    return String(midi_in->getPortName(index).c_str());
  }
  return "MidiIn is not initialized";
}


void MidiIn::open_port(int index) {
  if(midi_in) {
    midi_in->openPort(index);
    midi_in->ignoreTypes( true, true, true );
  }
}

bool MidiIn::is_port_open() {
  if(midi_in)
    return midi_in->isPortOpen();
  return false;
}

void MidiIn::close_port() {
  if(midi_in) {
    midi_in->closePort();
  }
}


int MidiIn::get_message() {
  if(midi_in == nullptr) return -1;

  stamp = midi_in->getMessage(&message);
  nBytes = message.size();
  for (auto i=0; i<nBytes; i++ ) {
    printf("Byte %d = %d", i, (int)message[i]);
  }
  if ( nBytes > 0 ) {
    printf("stamp = %f\n", stamp);
  }
  return nBytes;
}

int MidiIn::get_byte(int index) {
  if (message.size() > 0 && index < nBytes) {
    return (int)message[index];
  }
  return -1;
}

double MidiIn::get_stamp() {
  return stamp;
}


void MidiIn::_bind_methods() {
  ClassDB::bind_method(D_METHOD("init"), &MidiIn::init);

  ClassDB::bind_method(D_METHOD("get_number_of_ports"), &MidiIn::get_number_of_ports);
  ClassDB::bind_method(D_METHOD("get_port_name", "index"), &MidiIn::get_port_name);

  ClassDB::bind_method(D_METHOD("open_port", "index"), &MidiIn::open_port);
  ClassDB::bind_method(D_METHOD("is_port_open", ""), &MidiIn::is_port_open);
  ClassDB::bind_method(D_METHOD("close_port"), &MidiIn::close_port);

  ClassDB::bind_method(D_METHOD("get_message"), &MidiIn::get_message);
  ClassDB::bind_method(D_METHOD("get_byte", "byte"), &MidiIn::get_byte);
  ClassDB::bind_method(D_METHOD("get_stamp"), &MidiIn::get_stamp);
}

MidiIn::MidiIn() {
  stamp = 0.0;
  nBytes = 0;
}

MidiIn::~MidiIn() {
  if(midi_in) {
    delete midi_in;
  }
}
