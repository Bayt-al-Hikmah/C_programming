#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

typedef uint8_t  BYTE;
typedef uint32_t DWORD;
typedef int32_t  LONG;
typedef uint16_t WORD;

typedef struct {
WORD bfType;
DWORD bfSize;
WORD bfReserved1;
WORD bfReserved2;
DWORD bfOffBits; } __attribute__((__packed__))
BITMAPFILEHEADER;

typedef struct {
DWORD biSize;
LONG biWidth;
LONG biHeight;
WORD biPlanes;
WORD biBitCount;
DWORD biCompression;
DWORD biSizeImage;
LONG biXPelsPerMeter;
LONG biYPelsPerMeter;
DWORD biClrUsed;
DWORD biClrImportant;  } __attribute__((__packed__))
BITMAPINFOHEADER;

typedef struct{
BYTE B;
BYTE G;
BYTE R;
} __attribute__((__packed__))pixel;

void free_element(char** c, int h){
    for (int i = 0; i < h; i++){
        free(*(c + i));
    }
    free(c);
    return;

}
void create_array(char*** c, int h, int w){
    *(c) = calloc(h, sizeof(char*));
    for (int i = 0; i < h; i++){
        *(*(c) + i) = calloc(w + 2, sizeof(char));
    }

    return;

}
void pixel2char(FILE *input, char** c, int h, int w){
	WORD gray;
    pixel p;
    for(int i = 0; i < h ; i++){
		for(int j = 0; j < w; j++){
			fread(&p, sizeof(pixel), 1, input);
			gray = (p.G + p.B + p.R) / 3;
			if(gray <= 25){
                *(*(c + i) + j) = '@';
            }else if(gray <= 50){
                *(*(c + i) + j) = '%';
            }else if(gray <= 75){
                *(*(c + i) + j) = '#';
            }else if(gray <= 100){
                *(*(c + i) + j) = '*';
            }else if(gray <= 125){
                *(*(c + i) + j) = '+';
            }else if(gray <= 150){
                *(*(c + i) + j) = '=';
            }else if(gray <= 175){
                *(*(c + i) + j) = '-';
            }else if(gray <= 200){
                *(*(c + i) + j) = ':';
            }else if(gray <= 225){
                *(*(c + i) + j) = '.';
            }else{
                *(*(c + i) + j) = ' ';
            }
 
		}
        *(*(c + i) + w) = '\n';
	}
    return ;

}
void write_chars(FILE *output, char** c, int h, int w){
    for (int i = h-1; i >= 0; i--){
        for (int j = 0; j <= w; j++){
            fputc(*(*(c + i) + j), output);
        }
    }
    return ;
}
int main(int argc, char *argv[]){
    BITMAPINFOHEADER binfo;
    BITMAPFILEHEADER bheader;
    char **c;
    int h = 0, w = 0, i, j;
    FILE *input = fopen(argv[1], "r");
	FILE *output = fopen(argv[2], "w");
	fread(&bheader, sizeof(BITMAPFILEHEADER), 1, input);
	fread(&binfo, sizeof(BITMAPINFOHEADER), 1, input);
	w = abs(binfo.biWidth);
	h = abs(binfo.biHeight);
    create_array(&c, h, w);
    int s=(bheader.bfOffBits - sizeof(BITMAPFILEHEADER));
    fseek(input, bheader.bfOffBits, SEEK_SET);
    pixel2char(input, c, h, w);
    write_chars(output, c, h, w);
    free_element(c, h);
	fclose(input);
	fclose(output);
	return 0;
}

