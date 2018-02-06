/* register_types.cpp */

#include "register_types.h"
#include "class_db.h"
#include "summator.h"
#include "midi_in.h"
#include "midi_out.h"

void register_summator_types() {
  ClassDB::register_class<Summator>();
  ClassDB::register_class<MidiIn>();
  ClassDB::register_class<MidiOut>();
}

void unregister_summator_types() {
   //nothing to do here
}
