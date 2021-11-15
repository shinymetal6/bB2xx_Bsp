#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdint.h>
#include <time.h>
#include <sys/sysmacros.h>

unsigned char bmp[10][4096];

int do_blue(void)
{
char    fname_src[128], fname_dest[128];
struct  stat sb;
FILE    *fpin,*fpout;
int     i,j,k,single_size;
    for(j=0;j<10;j++)
    {
        sprintf(fname_src,"/Devel/Stm32Sw/bB2xx_Bsp/Core/Src/bB2xx_Bsp/SrcImages/blue%d.bmp",j);
        lstat(fname_src, &sb);
        single_size = ( int )sb.st_size;
        fpin = fopen (fname_src, "r");
        if ( fpin == NULL )
        {
            printf( "Unable to open %s for read\n",fname_src ) ;
            return -1;
        }
        fread(bmp[j],single_size,1,fpin);
        fclose(fpin);
    }
    printf( "Size : %d\n",single_size ) ;

    sprintf(fname_dest,"/Devel/Stm32Sw/bB2xx_Bsp/Core/Src/bB2xx_Bsp/Images/blue_digits.c");
    fpout = fopen (fname_dest, "w");
    fprintf(fpout,"#include \"main.h\"\n");
    fprintf(fpout,"__attribute__((section(\".table\"))) __attribute__ ((aligned (16))) const uint8_t blue_digits[10][%d] = { \n",single_size);
    for(j=0;j<10;j++)
    {
        fprintf(fpout,"   {\n");
        fprintf(fpout,"   ");
        for(i=0;i<single_size;i++)
        {
            if ( k == 16)
            {
                k = 0;
                fprintf(fpout,"0x%02x,\n   ",bmp[j][i]);
            }
            else
            {
                k++;
                fprintf(fpout,"0x%02x, ",bmp[j][i]);
            }
        }
        k=0;
        fprintf(fpout,"\n   },\n");
    }
    fprintf(fpout,"};\n");
    fclose(fpout);
    return single_size;
}

int do_red(void)
{
char    fname_src[128], fname_dest[128];
struct  stat sb;
FILE    *fpin,*fpout;
int     i,j,k,single_size;
    for(j=0;j<10;j++)
    {
        sprintf(fname_src,"/Devel/Stm32Sw/bB2xx_Bsp/Core/Src/bB2xx_Bsp/SrcImages/red%d.bmp",j);
        lstat(fname_src, &sb);
        single_size = ( int )sb.st_size;
        fpin = fopen (fname_src, "r");
        if ( fpin == NULL )
        {
            printf( "Unable to open %s for read\n",fname_src ) ;
            return -1;
        }
        fread(bmp[j],single_size,1,fpin);
        fclose(fpin);
    }
    printf( "Size : %d\n",single_size ) ;

    sprintf(fname_dest,"/Devel/Stm32Sw/bB2xx_Bsp/Core/Src/bB2xx_Bsp/Images/red_digits.c");
    fpout = fopen (fname_dest, "w");
    fprintf(fpout,"#include \"main.h\"\n");
    fprintf(fpout,"__attribute__((section(\".table\"))) __attribute__ ((aligned (16))) const uint8_t red_digits[10][%d] = { \n",single_size);
    for(j=0;j<10;j++)
    {
        fprintf(fpout,"   {\n");
        fprintf(fpout,"   ");
        for(i=0;i<single_size;i++)
        {
            if ( k == 16)
            {
                k = 0;
                fprintf(fpout,"0x%02x,\n   ",bmp[j][i]);
            }
            else
            {
                k++;
                fprintf(fpout,"0x%02x, ",bmp[j][i]);
            }
        }
        k=0;
        fprintf(fpout,"\n   },\n");
    }
    fprintf(fpout,"};\n");
    fclose(fpout);
    return single_size;
}

int do_green(void)
{
char    fname_src[128], fname_dest[128];
struct  stat sb;
FILE    *fpin,*fpout;
int     i,j,k,single_size;
    for(j=0;j<10;j++)
    {
        sprintf(fname_src,"/Devel/Stm32Sw/bB2xx_Bsp/Core/Src/bB2xx_Bsp/SrcImages/green%d.bmp",j);
        lstat(fname_src, &sb);
        single_size = ( int )sb.st_size;
        fpin = fopen (fname_src, "r");
        if ( fpin == NULL )
        {
            printf( "Unable to open %s for read\n",fname_src ) ;
            return -1;
        }
        fread(bmp[j],single_size,1,fpin);
        fclose(fpin);
    }
    printf( "Size : %d\n",single_size ) ;

    sprintf(fname_dest,"/Devel/Stm32Sw/bB2xx_Bsp/Core/Src/bB2xx_Bsp/Images/green_digits.c");
    fpout = fopen (fname_dest, "w");
    fprintf(fpout,"#include \"main.h\"\n");
    fprintf(fpout,"__attribute__((section(\".table\"))) __attribute__ ((aligned (16))) const uint8_t green_digits[10][%d] = { \n",single_size);
    for(j=0;j<10;j++)
    {
        fprintf(fpout,"   {\n");
        fprintf(fpout,"   ");
        for(i=0;i<single_size;i++)
        {
            if ( k == 16)
            {
                k = 0;
                fprintf(fpout,"0x%02x,\n   ",bmp[j][i]);
            }
            else
            {
                k++;
                fprintf(fpout,"0x%02x, ",bmp[j][i]);
            }
        }
        k=0;
        fprintf(fpout,"\n   },\n");
    }
    fprintf(fpout,"};\n");
    fclose(fpout);
    return single_size;
}

int do_orange(void)
{
char    fname_src[128], fname_dest[128];
struct  stat sb;
FILE    *fpin,*fpout;
int     i,j,k,single_size;
    for(j=0;j<10;j++)
    {
        sprintf(fname_src,"/Devel/Stm32Sw/bB2xx_Bsp/Core/Src/bB2xx_Bsp/SrcImages/orange%d.bmp",j);
        lstat(fname_src, &sb);
        single_size = ( int )sb.st_size;
        fpin = fopen (fname_src, "r");
        if ( fpin == NULL )
        {
            printf( "Unable to open %s for read\n",fname_src ) ;
            return -1;
        }
        fread(bmp[j],single_size,1,fpin);
        fclose(fpin);
    }
    printf( "Size : %d\n",single_size ) ;

    sprintf(fname_dest,"/Devel/Stm32Sw/bB2xx_Bsp/Core/Src/bB2xx_Bsp/Images/orange_digits.c");
    fpout = fopen (fname_dest, "w");
    fprintf(fpout,"#include \"main.h\"\n");
    fprintf(fpout,"__attribute__((section(\".table\"))) __attribute__ ((aligned (16))) const uint8_t orange_digits[10][%d] = { \n",single_size);
    for(j=0;j<10;j++)
    {
        fprintf(fpout,"   {\n");
        fprintf(fpout,"   ");
        for(i=0;i<single_size;i++)
        {
            if ( k == 16)
            {
                k = 0;
                fprintf(fpout,"0x%02x,\n   ",bmp[j][i]);
            }
            else
            {
                k++;
                fprintf(fpout,"0x%02x, ",bmp[j][i]);
            }
        }
        k=0;
        fprintf(fpout,"\n   },\n");
    }
    fprintf(fpout,"};\n");
    fclose(fpout);
    return single_size;
}

int do_yellow(void)
{
char    fname_src[128], fname_dest[128];
struct  stat sb;
FILE    *fpin,*fpout;
int     i,j,k,single_size;
    for(j=0;j<10;j++)
    {
        sprintf(fname_src,"/Devel/Stm32Sw/bB2xx_Bsp/Core/Src/bB2xx_Bsp/SrcImages/yellow%d.bmp",j);
        lstat(fname_src, &sb);
        single_size = ( int )sb.st_size;
        fpin = fopen (fname_src, "r");
        if ( fpin == NULL )
        {
            printf( "Unable to open %s for read\n",fname_src ) ;
            return -1;
        }
        fread(bmp[j],single_size,1,fpin);
        fclose(fpin);
    }
    printf( "Size : %d\n",single_size ) ;

    sprintf(fname_dest,"/Devel/Stm32Sw/bB2xx_Bsp/Core/Src/bB2xx_Bsp/Images/yellow_digits.c");
    fpout = fopen (fname_dest, "w");
    fprintf(fpout,"#include \"main.h\"\n");
    fprintf(fpout,"__attribute__((section(\".table\"))) __attribute__ ((aligned (16))) const uint8_t yellow_digits[10][%d] = { \n",single_size);
    for(j=0;j<10;j++)
    {
        fprintf(fpout,"   {\n");
        fprintf(fpout,"   ");
        for(i=0;i<single_size;i++)
        {
            if ( k == 16)
            {
                k = 0;
                fprintf(fpout,"0x%02x,\n   ",bmp[j][i]);
            }
            else
            {
                k++;
                fprintf(fpout,"0x%02x, ",bmp[j][i]);
            }
        }
        k=0;
        fprintf(fpout,"\n   },\n");
    }
    fprintf(fpout,"};\n");
    fclose(fpout);
    return single_size;
}

int do_digit(char *digit_name)
{
char    fname_src[128], fname_dest[128];
struct  stat sb;
FILE    *fpin,*fpout;
int     i,j,k,single_size;
    for(j=0;j<10;j++)
    {
        sprintf(fname_src,"/Devel/Stm32Sw/bB2xx_Bsp/Core/Src/bB2xx_Bsp/SrcImages/%s%d.bmp",digit_name,j);
        lstat(fname_src, &sb);
        single_size = ( int )sb.st_size;
        fpin = fopen (fname_src, "r");
        if ( fpin == NULL )
        {
            printf( "Unable to open %s for read\n",fname_src ) ;
            return -1;
        }
        fread(bmp[j],single_size,1,fpin);
        fclose(fpin);
    }
    printf( "On digit %s size is %d\n",digit_name,single_size ) ;

    sprintf(fname_dest,"/Devel/Stm32Sw/bB2xx_Bsp/Core/Src/bB2xx_Bsp/Images/%s_digits.c",digit_name);
    fpout = fopen (fname_dest, "w");
    fprintf(fpout,"#include \"main.h\"\n");
    fprintf(fpout,"__attribute__((section(\".table\"))) __attribute__ ((aligned (16))) const uint8_t %s_digits[10][%d] = { \n",digit_name,single_size);
    for(j=0;j<10;j++)
    {
        fprintf(fpout,"   {\n");
        fprintf(fpout,"   ");
        for(i=0;i<single_size;i++)
        {
            if ( k == 16)
            {
                k = 0;
                fprintf(fpout,"0x%02x,\n   ",bmp[j][i]);
            }
            else
            {
                k++;
                fprintf(fpout,"0x%02x, ",bmp[j][i]);
            }
        }
        k=0;
        fprintf(fpout,"\n   },\n");
    }
    fprintf(fpout,"};\n");
    fclose(fpout);
    return single_size;
}

int main()
{
FILE    *fpout;
char    fname_dest[128];
int     single_size;

/*
    single_size = do_blue();
    single_size = do_red();
    single_size = do_green();
    single_size = do_orange();
    single_size = do_yellow();
    */
    single_size = do_digit("blue");
    single_size = do_digit("red");
    single_size = do_digit("yellow");
    single_size = do_digit("green");
    single_size = do_digit("orange");

    sprintf(fname_dest,"/Devel/Stm32Sw/bB2xx_Bsp/Core/Src/bB2xx_Bsp/Images/digits.h");
    fpout = fopen (fname_dest, "w");

    fprintf(fpout,"#ifndef SRC_BB2XX_BSP_IMAGES_DIGITS_H_\n");
    fprintf(fpout,"#define SRC_BB2XX_BSP_IMAGES_DIGITS_H_\n\n");
    fprintf(fpout,"#define  DIGITS_X    28\n");
    fprintf(fpout,"#define  DIGITS_Y    50\n");
    fprintf(fpout,"extern const uint8_t blue_digits[10][%d];\n",single_size);
    fprintf(fpout,"extern const uint8_t green_digits[10][%d];\n",single_size);
    fprintf(fpout,"extern const uint8_t red_digits[10][%d];\n\n",single_size);
    fprintf(fpout,"extern const uint8_t yellow_digits[10][%d];\n\n",single_size);
    fprintf(fpout,"extern const uint8_t orange_digits[10][%d];\n\n",single_size);
    fprintf(fpout,"#endif /* SRC_BB2XX_BSP_IMAGES_DIGITS_H_ */\n");
    fclose(fpout);

}
