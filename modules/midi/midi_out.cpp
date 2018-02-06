/* midi_out.cpp */

#include "midi_out.h"


bool MidiOut::init() {
  try {
    midi_out = new RtMidiOut();
  } catch (RtMidiError &error) {
    error.printMessage();
  }
  if(midi_out) {
    return true;
  }
  return false;
}

int MidiOut::get_number_of_ports() {
  if (midi_out) {
    return midi_out->getPortCount();
  }
  return -1;
}

String MidiOut::get_port_name(int index) {
  return String(midi_out->getPortName(index).c_str());
}

void MidiOut::open_port(int index) {
  if(midi_out) {
    midi_out->openPort(index);
  }
}

bool MidiOut::is_port_open() {
  if(midi_out) {
    return midi_out->isPortOpen();
  }
  return false;
}

void MidiOut::close_port() {
  if(midi_out) {
    midi_out->closePort();
  }
}

void MidiOut::send_message(int b0, int b1, int b2) {
  message.clear();
  message.push_back(b0);
  message.push_back(b1);
  message.push_back(b2);
  if(midi_out) {
    midi_out->sendMessage(&message);
  }
}


void MidiOut::_bind_methods() {
  ClassDB::bind_method(D_METHOD("init"), &MidiOut::init);

  ClassDB::bind_method(D_METHOD("get_number_of_ports"), &MidiOut::get_number_of_ports);
  ClassDB::bind_method(D_METHOD("get_port_name", "index"), &MidiOut::get_port_name);

  ClassDB::bind_method(D_METHOD("open_port", "value"), &MidiOut::open_port);
  ClassDB::bind_method(D_METHOD("is_port_open"), &MidiOut::is_port_open);
  ClassDB::bind_method(D_METHOD("close_port"), &MidiOut::close_port);

  ClassDB::bind_method(D_METHOD("send_message", "b0", "b1", "b2"), &MidiOut::send_message);
}

MidiOut::MidiOut() {
}

MidiOut::~MidiOut() {
    if(midi_out) {
      delete midi_out;
    }
}
