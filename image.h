void imwriter(int p[][500])
{
   int i=500,j=500,x=0,max=255;
   FILE *f;
   char s1[3]="P5",com[]="#test.pgm",s2[]="500 500",s3[]="255";
   
   f=fopen("test.pgm","w");
   fputs(s1,f);fputc('\n',f);
   fputs(com,f);fputc('\n',f);
   fprintf(f,"%d %d",i,j);fputc('\n',f);
   fprintf(f,"%d",max);fputc('\n',f);
   for( i=0;i<500;i++)
      for(j=0;j<500;j++)
          fprintf(f,"%c",*(*(p)+i*500+j));
   fclose(f);
}
