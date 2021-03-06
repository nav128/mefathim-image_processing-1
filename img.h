 /* ==================================================================== *\
|				Declarations used for extrnal loadable .BMP files			   |
 \* ==================================================================== */
#ifndef	__img_h
#define	__img_h

#include <windows.h>

typedef struct _img IMG;

#ifdef	__cplusplus
extern "C" {
#endif


// Allocate and construct an image by Loading it from a file.
// Currently only .BMP files are supported.
// Returns NULL if failed to load. 
// Call img_delete() when the image is no longer needed.
// -------------------------------------------------------------------
IMG *img_load(const char path[]);


// Allocate and construct a new grey image from a colored image.
// Retruns image or null. If the colored image is already a grey image
// null is returned. To check if an image is grey call img_planes().
// call img_delete() when no longer needed.
// --------------------------------------------------------------------
IMG *img_to_grey(const IMG *imgColored); 


// ----------------------------------------------------------------------------------
// allocate HBITMAP and populate the bits. 
// If the image is colored, a 24 bits per color bitmap is generated.
// If the image is grey, a paletted 8 bits bitmap is generated.
// in case of failure (HBITMAP)0 is returned
// ----------------------------------------------------------------------------------
HBITMAP img_dib(HDC hdc, const IMG *img);



void img_dim(int *width, int *height, const IMG *img);

// ---------------------------------------------------------------
// delete an image that was created by img_load() or img_to_grey()
// ---------------------------------------------------------------
void img_delete(IMG *img);

IMG *img_dtor (IMG *img); // destructor for internal use



#ifdef	__cplusplus
}
#endif


#endif



