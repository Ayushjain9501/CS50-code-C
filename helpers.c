// Helper functions for music

#include <cs50.h>
#include <string.h>
#include <math.h>

#include "helpers.h"

// Converts a fraction formatted as X/Y to eighths
int duration(string fraction)
{

    //using strtok as used in snthesize.c to separate numerator and denominator from beat time
    string numerator = strtok(fraction, "/");
    string denominator = strtok(NULL, "/");
    //convert string arguments to integers for operation
    int a = atoi(numerator), b = atoi(denominator);
    int noOfEighths = (a * 8) / b;
    //return the number of eighths
    return noOfEighths;
}

// Calculates frequency (in Hz) of a note
int frequency(string note)
{
    //here the variable store the change of 1 or -1 semitone caused by accidental
    //also octave stores the number of ocatave from 0-7
    int accidental, octave;
    //notechar stores the beat
    char noteChar;
    //check if an accidental is present
    if (strlen(note) == 3)
    {
        //values assigned will be more clear if a look at the algorithm to calculate change is taken
        noteChar = note[0];
        switch (note[1])
        {
            case '#' :
            {
                accidental = 1;
                break;
            }

            case 'b' :
            {
                accidental = -1;
                break;
            }

            default :
                accidental = 0;
        }
        //since note[2] is an char integer octave will by default store its ASCII value
        //so subtract ascii value of '0'
        octave = note[2] - '0';
    }

    else
    {
        //assignment for notes without accidentals
        noteChar = note[0];
        accidental = 0;
        octave = note[1] - '0' ;
    }

    int noteValue;
    switch (noteChar)
    {
        //taking A note to be 0, number of semi=tone change is assigned
        case 'C' :
            noteValue = -9;
            break;
        case 'D' :
            noteValue = -7;
            break;
        case 'E' :
            noteValue = -5;
            break;
        case 'F' :
            noteValue = -4;
            break;
        case 'G' :
            noteValue = -2;
            break;
        case 'A' :
            noteValue = 0;
            break;
        case 'B' :
            noteValue = 2;
            break;
        default :
            noteValue = 0;
    }
    //since we know the value of 'A' in octave 4, octave difference causes change of 12 semitones, we caluclute octave difference
    int octaveDifference = octave - 4;
    //change of 12 semitones for octave change
    //change caused by accidental
    //change caused by note letter
    double n = 12 * (octaveDifference) + noteValue + accidental;
    double change = pow(2, n / 12);
    //rounds the value to integers
    int freq = round(change * 440);
    return freq;
}

// Determines whether a string represents a rest
bool is_rest(string s)
{
    // empty space is stored as "" , so checks it
    if (!strcmp(s, ""))
    {
        return true;
    }
    return false;
}
