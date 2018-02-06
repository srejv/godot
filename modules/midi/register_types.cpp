/* register_types.cpp */

#include "register_types.h"
#include "class_db.h"
#include "midi_in.h"
#include "midi_out.h"

void register_midi_types() {
  ClassDB::register_class<MidiIn>();
  ClassDB::register_class<MidiOut>();
}

void unregister_midi_types() {
   //nothing to do here
}
