#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<fcntl.h>
int main(void)
{
   system("echo password | sudo -S -v");                  /* Replace password with your device password.
                                                             Linux users can skip this part.                        */
                                                             
   system("sudo ifconfig en0 ether AA:BB:CC:DD:EE:FF");   /* Replace en0 with your physical network id.
                                                             Replace AA:BB:CC:DD:EE:FF with the required MAC address.
                                                             This mac address is registered on the network you are 
                                                             connecting to. Linux users don't need the sudo.        */
   
   system("ifconfig en0 | grep ether > mac.txt");         /* Your MAC address has been changed. To provide an user 
                                                             interactive console. We'll store & print the results.  */
   system("clear");
   int fd = open("mac.txt",O_RDONLY);
   char *buf,*sptr;
   read(fd,buf,25);
   char* token = strtok_r(buf," ",&sptr);
   printf("MAC has been changed to: %s\n",sptr);
   return 0; 
}
