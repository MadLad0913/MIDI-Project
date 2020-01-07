#include <iostream>
#include <fstream>
#include "MIDI Utilities.h"

int main()
{
	std::ifstream In_File("C:\\Users\\micah\\Documents\\Twinkle.mid", std::ios::binary | std::ios::in);
	if (!In_File)
	{
		std::cerr << "Problem opening file!";
		return 1;
	}

	MIDI_CHUNK_HEADER midi_chunk_header;
	In_File.read((char*)&midi_chunk_header, sizeof(MIDI_CHUNK_HEADER));
	std::cout << "File type is: "<< midi_chunk_header.MThd << std::endl;
	std::cout << "Bytes to follow: " << midi_chunk_header.ChunckSize << std::endl;
	std::cout << "MIDI Format: " << midi_chunk_header.Format << std::endl;
	std::cout << "MIDI Track: " << midi_chunk_header.Track << std::endl;
	std::cout << "MIDI Time Division: " << midi_chunk_header.TimeDivision << std::endl;

	std::cout << "==========================================" << std::endl; 

	MIDI_TRACK_HEADER midi_track_header;
	In_File.read((char*)&midi_track_header, sizeof(MIDI_TRACK_HEADER));
	std::cout << "File type is: " << midi_track_header.MTrk << std::endl;
	std::cout << "Bytes to follow: " << midi_track_header.ChunckSize << std::endl;
	std::cout << "Delta time duration: " << midi_track_header.VariableLengthData << std::endl;
	std::cout << "Status Byte:" << midi_track_header.StatusByte << std::endl;
	std::cout << "Data Bytes:" << midi_track_header.DataBytes << std::endl;
}
