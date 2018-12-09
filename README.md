# Questions

## What's `stdint.h`?

A Library that contains different integer data types along wtih their widths based on microsoft's alias for C/C++ primitve data types.

## What's the point of using `uint8_t`, `uint32_t`, `int32_t`, and `uint16_t` in a program?

These are unsigned integers and are used to store data. Ex - uint8_t stores a 8 bit integer (from 0 to 255).

## How many bytes is a `BYTE`, a `DWORD`, a `LONG`, and a `WORD`, respectively?

SInce 8 Bits equal a Byte.
BYTE is 1 byte.
DWORD is 4 bytes.
LONG is 4 bytes.
WORD is 2 bytes.

## What (in ASCII, decimal, or hexadecimal) must the first two bytes of any BMP file be? Leading bytes used to identify file formats (with high probability) are generally called "magic numbers."

bfType stores the file type. It must be BM for Bitmap.
The Characters 'B' and 'M' are in ASCII encoding.

## What's the difference between `bfSize` and `biSize`?

bfSize is the size of the Bitmap file whereas biSize is the size of tagBITMAPINFOHEADER structure.

## What does it mean if `biHeight` is negative?

If biHeight is negative, the bitmap is a top-down DIB(Device - Independent Bitmaps) and its origin is the upper-left corner.

## What field in `BITMAPINFOHEADER` specifies the BMP's color depth (i.e., bits per pixel)?

biBitCount

## Why might `fopen` return `NULL` in lines 24 and 32 of `copy.c`?

There might be insufficient memory to be allocated to the input and output files!

## Why is the third argument to `fread` always `1` in our code?

The third argumenet species the number of elements (of size corresponding to second argument) to be read. In our case, it is one at a time.
hence, it is always 1.

## What value does line 65 of `copy.c` assign to `padding` if `bi.biWidth` is `3`?

We have
padding = (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4, Size of RGBTRIPLE Structure is 3 Bytes.
So,
padding = (4 - (3 * 3) % 4) % 4
padding = ((4 - 9) % 4) % 4
padding = (-5 % 4) % 4
padding = 3 % 4
padding = 3
The value assigned is 3.


## What does `fseek` do?

fseek sets the position of cursor to the desired offset.
It accepts three arguments
1)Pointer to File
2)Number of bytes to offset from the Third argument.
3)Specifies the location to offset from!

## What is `SEEK_CUR`?

It says fseek to offset from the current cursor Location!

## Whodunit?

It was Professor Plum with the candlestick in the library.
