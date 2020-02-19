#include "MidiFile.h"
#include "Options.h"
#include <iostream>
#include <iomanip>

using namespace std;
using namespace smf;

int main() {
   MidiFile midifile;
   midifile.read("C:Users\\micah\\Downloads\\la_campanella.mid");
   midifile.doTimeAnalysis();
   midifile.linkNotePairs();

   int tracks = midifile.getTrackCount();
   cout << "TPQN: " << midifile.getTicksPerQuarterNote() << endl;
   cout << "TRACKS: " << tracks << endl;
   cout << "Tick\tSeconds\tDur\tMessage" << endl;
   for (int event=0; event<midifile[track].size(); event++) {
      cout << dec << midifile[track][event].tick;
      cout << '\t' << dec << midifile[track][event].seconds;
      cout << '\t';
      if (midifile[track][event].isNoteOn())
         cout << midifile[track][event].getDurationInSeconds();
      cout << '\t' << hex;
      for (int i=0; i<midifile[track][event].size(); i++)
         cout << (int)midifile[track][event][i] << ' ';
      cout << endl;
      }
   }
   return 0;
}
