#include <stdint.h>

struct MIDI_CHUNK_HEADER {
	char               MThd[4]; //char[4]
	uint32_t           ChunckSize; //DWORD
	uint16_t           Format; //WORD
	uint16_t           Track; //WORD
	uint16_t           TimeDivision; //WORD
};

struct MIDI_TRACK_HEADER {
	char               MTrk[4]; //char[4]
	uint32_t           ChunckSize; //DWORD
	uint32_t           VariableLengthData; //MAXIMUM 4 BYTES LONG
	uint8_t            StatusByte; //1 BYTE IN TOTAL
	uint16_t           DataBytes[2]; // 2 BYTES IN TOTAL
};
