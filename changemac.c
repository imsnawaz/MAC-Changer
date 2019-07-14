#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<fcntl.h>
int main(void)
{
   char query[50]="sudo ifconfig en0 ether ";               /* Replace en0 with your physical network id. 
                                                               It is usually en0. Format "en<digit>" */
   char mac[18],*buf,*token;
   printf("Enter MAC (in lowerCase AlphaNumeric) : ");      
   fgets(mac,18,stdin);                                     /* Enter the MAC address. This mac address is 
                                                               registered on the network you are connecting to. */
   strcat(query,mac);                                       
   system(query);                                           /* This is the system call for MAC change. If asked
                                                               enter the user password (usually in OSX). */
   
   system("ifconfig en0 | grep ether > mac.txt");           /* To verify, we'll store the current MAC address 
                                                               in "mac.txt" file. */
   system("clear");
   int fd = open("mac.txt",O_RDONLY);
   read(fd,buf,25);
   token = strtok(buf, " ");
   token = strtok(NULL, " ");
                                                            /* If the current MAC Address matches our
                                                               requested Address, notify success. */
   if(strcmp(token,mac)==0)
      printf("Mac change successful!\nCurrent MAC Address: %s\n",token);
   else
      printf("Mac change failed!\n");
   return 0; 
}
