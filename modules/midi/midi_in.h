/* midi_in.h */
#ifndef MIDI_IN_H
#define MIDI_IN_H

#include "reference.h"
#include "thirdparty/rtmidi/RtMidi.h"
#include <vector>

class MidiIn : public Reference {
  GDCLASS(MidiIn, Reference)

  std::vector<unsigned char> message;
  double stamp;
  int nBytes;
  RtMidiIn* midi_in;

protected:
  static void _bind_methods();

public:
  bool init();

  int get_number_of_ports();
  String get_port_name(int index);

  void open_port(int index);
  bool is_port_open();
  void close_port();

  int get_message();
  int get_byte(int byte);
  double get_stamp();

  MidiIn();
  ~MidiIn();
};

#endif
