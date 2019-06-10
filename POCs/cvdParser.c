#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <zlib.h>
#include <memory.h>

#define BLOCK_SIZE 512

int main(int argc, char** argv) {
    int fileDescripor;
    gzFile zipedSignatureFile;
    int lineCounter = 0;
    char buffer[BLOCK_SIZE];
    char osize[13];
    unsigned int size, pad;
    unsigned int type;

    if( argc < 2 ) {
        printf("Provide the path to cvd file\n");
        return -1;
    }

    fileDescripor = open(argv[1], O_RDONLY);
    if( fileDescripor == -1 ) {
        printf("Not able to open %s", argv[1]);
        return -1;
    }

    printf("Succesfully opened handle\n");
    lseek(fileDescripor, BLOCK_SIZE, SEEK_SET);

    zipedSignatureFile = gzdopen(fileDescripor, "rb");
    if( zipedSignatureFile == NULL ) {
        printf("Failed to open gzip file\n");
        close(fileDescripor);
    }

    while(lineCounter < 8) {
        memset(buffer, 0, BLOCK_SIZE);
        gzread(zipedSignatureFile, buffer, BLOCK_SIZE);
        type = buffer[156];
	    strncpy(osize, buffer + 124, 12);
	    osize[12] = '\0';

	    sscanf(osize, "%o", &size);
        pad = size % BLOCK_SIZE ? (BLOCK_SIZE - (size % BLOCK_SIZE)) : 0;
        printf("File:%s size:%d\n", buffer, size);
        gzseek(zipedSignatureFile, size+pad, SEEK_CUR);
        lineCounter++;
    }

    close(fileDescripor);
    return 0;
}
