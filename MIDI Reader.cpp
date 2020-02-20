#include "MidiFile.h"
#include "Options.h"
#include <iostream>
#include <iomanip>

using namespace std;
using namespace smf;

int main() {
	MidiFile midifile;
	midifile.read("C:Users\\micah\\Downloads\\la_campanella.mid.mid");
	cout << "TPQ: " << midifile.getTicksPerQuarterNote() << endl;
	cout << "TRACKS: " << midifile.getTrackCount() << endl;
	midifile.joinTracks();
	// midifile.getTrackCount() will now return "1", but original
	// track assignments can be seen in .track field of MidiEvent.
	cout << "TICK    DELTA   TRACK   MIDI MESSAGE\n";
	cout << "____________________________________\n";
	MidiEvent* mev;
	int deltatick;
	for (int event = 0; event < midifile[0].size(); event++) {
		mev = &midifile[0][event];
		if (event == 0) deltatick = mev->tick;
		else deltatick = mev->tick - midifile[0][event - 1].tick;
		cout << dec << mev->tick;
		cout << '\t' << deltatick;
		cout << '\t' << mev->track;
		cout << '\t' << hex;
		for (int i = 0; i < mev->size(); i++)
			cout << (int)(*mev)[i] << ' ';
		cout << endl;
	}
	return 0;
}
