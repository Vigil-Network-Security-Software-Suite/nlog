#include <vigil/vigil.h>
#include <sys/socket.h>
#include <netdb.h>
#include <linux/if_ether.h>
#include <arpa/inet.h>
#include <string.h>
#include <stdlib.h>
int main(){

  int fd = socket(PF_PACKET, SOCK_RAW, htons(ETH_P_ALL));  
  // if(setsockopt(fd, SOL_SOCKET, SO_BINDTODEVICE,))
  int len;
  struct sockaddr saddr;
  int saddr_sz = sizeof(saddr);
  unsigned char buffer[1600] = {0};
  while(1){
    len = recvfrom(fd, &buffer, 1600, 0, &saddr, (socklen_t *)&saddr_sz);
    struct rule_data * rdata = full_decode(buffer,len);
    free_rdata(rdata);
  }
} 