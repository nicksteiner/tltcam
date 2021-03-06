/***********************************************************************************
 *  SnoozeAudio.h
 *  Teensy 3.x
 *
 * Purpose: Audio Driver
 *
 ***********************************************************************************/
#include "Arduino.h"
#include "SnoozeAudio.h"
/***********************************************************************************/
#define PDB_CONFIG (PDB_SC_TRGSEL( 15 ) | PDB_SC_PDBEN | PDB_SC_CONT | PDB_SC_PDBIE | PDB_SC_DMAEN)
/*******************************************************************************
 *  disable PDB0
 *******************************************************************************/
void SnoozeAudio::disableDriver( void ) {
    PDB0_SC = 0;
}

/*******************************************************************************
 *  enable PDB0
 *******************************************************************************/
void SnoozeAudio::enableDriver( void ) {
    PDB0_SC = PDB_CONFIG | PDB_SC_LDOK;
    PDB0_SC = PDB_CONFIG | PDB_SC_SWTRIG;
}