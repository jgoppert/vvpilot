#include <stdio.h>     // Standard input/output definitions
#include <string.h>    // String function definitions
#include <unistd.h>   // UNIX standard function definitions
#include <fcntl.h>      // File control definitions
#include <errno.h>     // Error number definitions
#include <../termios.h>  // POSIX terminal control definitions 

// function to open the port
int open_port(void)
{
    int port;
    //open the port and store the file descriptor in 'port'
    port = open("/dev/ttyS0", O_RDWR | O_NOCTTY | O_NDELAY);
    if (port == -1) {
        // Could not open the port
        perror("open_port: Unable to open /dev/ttyS0 - ");
    } else {
        fcntl(port, F_SETFL, 0); //leave this
    }
    return (port);
}


int main()
{
    int port,n;
    char str[30];

    //termios - structure contains options for port manipulation
    struct termios specs; // for setting baud rate

    //setup part
    port = open_port();
    tcgetattr(port, &specs);

    //now the specs points to the opened port's specifications
    specs.c_cflag = (CLOCAL | CREAD ); //control flags


    //output flags
    //CR3 - delay of 150ms after transmitting every line
    /*specs.c_oflag = (OPOST | CR3);*/

    //set Baud Rate to 50bps
    cfsetospeed(&specs,B57600);


    //our custom specifications set to the port
    //TCSANOW - constant that prompts the system to set
    //specifications immediately.
    tcsetattr(port,TCSANOW,&specs);

    //execution part
    printf("\nEnter the data:\t");
    scanf("%s",str);
    n = write(port,str,11); // n = no of bytes written
    if (n<0) {
        printf("\nError");
    }


    //close the port
    close(port);
    return(0);
}

/* vim: set et fenc= ff=unix sts=0 sw=4 ts=4 : */
