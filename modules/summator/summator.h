/* summator.h */
#ifndef SUMMATOR_H
#define SUMMATOR_H

#pragma comment(lib, "winmm.lib")

#include "reference.h"
#include "thirdparty/rtmidi/RtMidi.h"
#include <vector>


class Summator : public Reference {
    GDCLASS(Summator, Reference);

    RtMidiIn* midi_in;

    std::vector<unsigned char> message;
protected:
    static void _bind_methods();

public:
    int init();

    int get_number_of_ports();
    void open_port(int value);
    int get_message();

    int get_message_part(int index);

    String get_midi_name(int index);

    Summator();
    ~Summator();
};


#endif
