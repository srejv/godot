/* midi_out.h */
#ifndef MIDI_OUT_H
#define MIDI_OUT_H

#include "reference.h"
#include "thirdparty/rtmidi/RtMidi.h"
#include <vector>

class MidiOut : public Reference {
  GDCLASS(MidiOut, Reference)

  RtMidiOut* midi_out;

  std::vector<unsigned char> message;
  double stamp;
  int nBytes;

protected:
  static void _bind_methods();

public:
  bool init();

  int get_number_of_ports();
  String get_port_name(int index);

  void open_port(int index);
  bool is_port_open();
  void close_port();

  void send_message(int b0, int b1, int b2);


  MidiOut();
  ~MidiOut();
};

#endif
