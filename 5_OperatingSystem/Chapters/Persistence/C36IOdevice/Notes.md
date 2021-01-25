# Crux P389
HOW TO INTEGRATE I/O INTO SYSTEMS
How should I/O be integrated into systems? 
What are the general
mechanisms?
How can we make them efficient?


# 36.1 System Architecture
1. there is also hierarchy in I/O devices:
    1. a single CPU attached to the main mem- ory of the system via some kind of memory bus or interconnect
    2. Some devices are connected to the system via a general I/O bus, which in many modern systems would be PCI (or one if its many derivatives); graph- ics and some other higher-performance I/O devices might be found here.
    3. Finally, even lower down are one or more of what we call a peripheral bus, such as SCSI, SATA, or USB.

2. why do we need a hierarchical struc- ture like this? Put simply: 
    physics, and cost.

3. The faster a bus is, the shorter it must be; In addition, engineering a bus for high performance is quite costly.
    
4. Thus, system designers have adopted this hierarchical approach, where components that demands high performance (such as the graphics card) are nearer the CPU.  Lower performance components are further away.


# 36.2 A Canonical Device
a device has two important components:
    * (接口) The first is the hardware interface it presents to the rest of the system.( harware must present interface to be controled by software)
    * (硬件内部实现功能) The second part of any device is its internal structure. This part of the device is implementation specific and is responsible for implement- ing the abstraction the device presents to the system. ( simple device need simple implementation; complex device need complex implementation )


# 36.3 The Canonical Protocol
refer to Figure 36.2 to understand
1. device interface is comprised of three registers:
    * a status register, which can be read to see the current sta- tus of the device;
    * a command register, to tell the device to perform a cer- tain task;
    * a data register to pass data to the device, or get data from the device.
By reading and writing these registers, the operating system can control device behavior.


see the code snipet to understand the utilization of the device
2. The protocol has four steps:
    * In the first, the OS waits until the device is ready to receive a command by repeatedly reading the status register; we call this polling the device (basically, just asking it what is going on).
    * Second, the OS sends some data down to the data register; 
    * Third, the OS writes a command to the command register; doing so implicitly lets the device know that both the data is present and that it should begin working on the com- mand.
    * Finally, the OS waits for the device to finish by again polling it in a loop, waiting to see if it is finished (it may then get an error code to indicate success or failure).

3. advantage and disadvantage of the basic protocol
This basic protocol has the positive aspect of being simple and work- ing. However, there are some inefficiencies and inconveniences involved:
    * The first problem you might notice in the protocol is that polling seems inefficient; specifically, it wastes a great deal of CPU time just waiting for the (potentially slow) device to complete its activity, instead of switching to another ready process and thus better utilizing the CPU.


# Crux 
HOW TO AVOID THE COSTS OF POLLING


# 36.4 Lowering CPU Overhead With Interrupts
1. __interrupt__
OS can issue a request, put the call- ing process to sleep, and context switch to another task.

2. Interrupts thus allow for overlap of computation and I/O.

3. Note that using interrupts is not always the best solution.
Thus, if a device is fast, it may be best to poll; if it is slow, interrupts, which allow overlap, are best.

4. best solution: hybrid
it may be best to use a hybrid that polls for a little while and then, if the device is not yet finished, uses interrupts.

5. Another reason not to use interrupts arises in networks:
    When a huge stream of incoming packets each generate an interrupt, it is pos- sible for the OS to livelock, that is, find itself only processing interrupts and never allowing a user-level process to run and actually service the requests.

6. Another interrupt-based optimization is coalescing.
    a device which needs to raise an interrupt first waits for a bit before deliv- ering the interrupt to the CPU. While waiting, other requests may soon complete, and thus multiple interrupts can be coalesced into a single in- terrupt delivery, thus lowering the overhead of interrupt processing.


# 36.5 More Efficient Data Movement With DMA
# Crux P394 
HOW TO LOWER PIO OVERHEADS
With PIO, the CPU spends too much time moving data to and from devices by hand. 
How can we offload this work and thus allow the CPU to be more effectively utilized?

1. The solution to this problem is something we refer to as __Direct Memory Access__ (DMA). A DMA engine is essentially a very specific device within a system that can orchestrate transfers between devices and main memory without much CPU intervention.

2. DMA works as follows:
    To transfer data to the device,  the OS would program the DMA engine by telling it where the data lives in memory, how much data to copy, and which device to send it to.
    * At that point, the OS is done with the transfer and can proceed with other work.
    * When the DMA is complete, the DMA controller raises an interrupt, and the OS thus knows the transfer is complete.


# 36.6 Methods Of Device Interaction
# Crux P394 
HOW TO COMMUNICATE WITH DEVICES
How should the hardware communicate with a device? 
Should there be explicit instructions? 
Or are there other ways to do it?

1. Over time, two primary methods of device communication have developed:
    * The first, oldest method is to have explicit I/O instructions.
These instructions specify a way for the OS to send data to specific device registers and thus allow the construction of the protocols described above.
    * The second method to interact with devices is known as memory- mapped I/O. With this approach, the hardware makes device registers available as if they were memory locations. To access a particular register, the OS issues a load (to read) or store (to write) the address; the hardware then routes the load/store to the device instead of main memory.

2. There is not some great advantage to one approach or the other. The memory-mapped approach is nice in that no new instructions are needed to support it, but both approaches are still in use today.


# 36.7 Fitting Into The OS: The Device Driver
# Crux P395
HOW TO BUILD A DEVICE-NEUTRAL OS
How can we keep most of the OS device-neutral, thus hiding the details of device interactions from major OS subsystems?

The problem is solved through the age-old technique of abstraction.

At the lowest level, a piece of software in the OS must know in detail how a device works. We call this piece of software a device driver, and any specifics of device interaction are encapsulated within.


# Most of OS code are used for manage the device!
Studies of the Linux kernel reveal that over 70% of OS code is found in device drivers 
for Windows-based systems, it is likely quite high as well.


# Summary
1. Two techniques, the interrupt and DMA, have been introduced to help with device efficiency
2. two approaches to access- ing device registers, explicit I/O instructions and memory-mapped I/O, have been described
3. Finally, the notion of a device driver has been pre- sented, showing how the OS itself can encapsulate low-level details and thus make it easier to build the rest of the OS in a device-neutral fashion.
