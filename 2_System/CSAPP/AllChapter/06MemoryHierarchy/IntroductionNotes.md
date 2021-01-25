1. In practice, a memory system is a hierarchy of storage devices with different capacities, costs, and access times.
2. CPU registers hold the most frequently used data.
3. Small, fast cache memories nearby the CPU act as staging areas for a subset of the data and instructions stored in the relatively slow main memory.
4. The main memory stages data stored on large, slow disks, which in turn often serve as staging areas for data stored on the disks or tapes of other machines connected by networks.
5. As a programmer, you need to understand the memory hierarchy because it has a big impact on the performance of your applications.
6. If the data your program needs are stored in a CPU register, then they can be accessed in 0 cycles during the execution of the instruction. If stored in a cache, 4 to 75 cycles. If stored in main memory, hundreds of cycles. And if stored in disk, tens of millions of cycles!
7. This idea centers around a fundamental property of computer programs known as **locality**.
8. Programs with good locality tend to access the same set of data items over and over again, or they tend to access sets of nearby data items. Programs with good locality tend to access more data items from the upper levels of the memory hierarchy than programs with poor locality, and thus run faster.
9. focus on the cache memories that act as staging areas between the CPU and main memory, be- cause they have the most impact on application program performance.
10. how to analyze your C programs for locality, and we introduce techniques for improving the locality in your programs.

# 6.1 Storage Technologies
1. Much of the success of computer technology stems from the tremendous progress in storage technology.

### 6.1.1 Random Access Memory
1. Random access memory (RAM) comes in two varieties—static and dynamic.
    * Static RAM (SRAM) is faster and significantly more expensive than dynamic RAM (DRAM). SRAM is used for cache memories, both on and off the CPU chip.
    * DRAM is used for the main memory plus the frame buffer of a graphics system.

**Static RAM**
2. SRAM stores each bit in a bistable memory cell. Each cell is implemented with a six-transistor circuit. This circuit has the property that it can stay indefinitely in either of two different voltage configurations, or states. Any other state will be unstable—starting from there, the circuit will quickly move toward one of the stable states.

**Dynamic RAN**
3. DRAM stores each bit as charge on a capacitor.
4. DRAM storage can be made very dense— each cell consists of a capacitor and a single access transistor.
5. DRAM memory cell is very sensitive to any disturbance. When the capacitor voltage is disturbed, it will never recover. Exposure to light rays will cause the capacitor voltages to change.
6. The memory system must periodically refresh every bit of memory by reading it out and then rewriting it.
7. Some systems also use error-correcting codes, where the computer words are encoded using a few more bits , such that circuitry can detect and correct any single erroneous bit within a word.

8. SRAM is persistent as long as power is applied. Unlike DRAM, no refresh is necessary.
9. SRAM can be accessed faster than DRAM.
10. SRAM is not sensitive to disturbances such as light and electrical noise.
11. The trade-off is that SRAM cells use more transistors than DRAM cells and thus have lower densities, are more expensive, and consume more power.

**Conventional DRANMs**
12. The cells (bits) in a DRAM chip are partitioned into d supercells, each consisting of w DRAM cells. A d × w DRAM stores a total of dw bits of information. The supercells are organized as a rectangular array with r rows and c columns, where r c = d .
13. Information flows in and out of the chip via external connectors called **pins**. Each pin carries a 1-bit signal.
14. Each DRAM chip is connected to some circuitry, known as the memory controller, that can transfer w bits at a time to and from each DRAM chip.
15. To read the contents of supercell (i, j ), the memory controller sends the row address i to the DRAM, followed by the column address j . The DRAM responds by sending the contents of supercell (i, j ) back to the controller.
16. One reason circuit designers organize DRAMs as two-dimensional arrays instead of linear arrays is to reduce the number of address pins on the chip.
17. The disadvantage of the two-dimensional array organization is that addresses must be sent in two distinct steps, which increases the access time.


**Memory Modules**
18. DRAM chips are packaged in memory modules that plug into expansion slots on the main system board (motherboard).
19. Each supercell stores 1 byte of main memory, and each 64-bit word at byte address A in main memory is represented by the eight supercells whose corresponding supercell address is (i,j).
20. To retrieve the word at memory address A, the memory controller converts A to a supercell address (i, j ) and sends it to the memory module, which then broadcasts i and j to each DRAM. In response, each DRAM outputs the 8-bit contents of its (i, j ) supercell. Circuitry in the module collects these outputs and forms them into a 64-bit word, which it returns to the memory controller.

**Nonvolatile Memory**
21. DRAMs and SRAMs are volatile in the sense that they lose their information if the supply voltage is turned off.
22. Nonvolatile memories, on the other hand, retain their information even when they are powered off.
23. read-only memories (ROMs)
24. Flash memory is a type of nonvolatile memory, based on EEPROMs, that has become an important storage technology.
25. Programs stored in ROM devices are often referred to as firmware. When a computer system is powered up, it runs firmware stored in a ROM. Some systems provide a small set of primitive input and output functions in firmware
26. Complicated devices such as graphics cards and disk drive controllers also rely on firmware to translate I/O (input/output) requests from the CPU.

**Accessing Main Memory**
27. Data flows back and forth between the processor and the DRAM main memory over shared electrical conduits called buses.
28. Each transfer of data between the CPU and memory is accomplished with a series of steps called a bus transaction.
29. A read transaction transfers data from the main memory to the CPU. A write transaction transfers data from the CPU to the main memory.
30. A bus is a collection of parallel wires that carry address, data, and control signals.
31. Depending on the particular bus design, data and address signals can share the same set of wires or can use different sets. Also, more than two devices can share the same bus. The control wires carry signals that synchronize the transaction and identify what kind of transaction is currently being performed.


### 6.1.2 Disk Storage
1. Disks are workhorse storage devices that hold enormous amounts of data, on the order of hundreds to thousands of gigabytes, as opposed to the hundreds or thousands of megabytes in a RAM-based memory.
2. However, it takes on the order of milliseconds to read information from a disk, a hundred thousand times longer than from DRAM and a million times longer than from SRAM.

**Disk Geometry**
3. Disks are constructed from platters. Each platter consists of two sides, or surfaces, that are coated with magnetic recording material. A rotating spindle in the center of the platter spins the platter at a fixed rotational rate, typically between 5,400 and 15,000 revolutions per minute (RPM). A disk will typically contain one or more of these platters encased in a sealed container.
4. Each surface consists of a collection of concentric rings called tracks. Each track is partitioned into a collection of sectors. Each sector contains an equal number of data bits (typically 512 bytes) encoded in the magnetic material on the sector. Sectors are separated by gaps where no data bits are stored. Gaps store formatting bits that identify sectors.

**Disk Capacity**
5. The maximum number of bits that can be recorded by a disk is known as its max- imum capacity, or simply capacity
6. Disk capacity is determined by the following technology factors:
    Recording density (bits/in). The number of bits that can be squeezed into a 1- inch segment of a track.
    Track density (tracks/in). The number of tracks that can be squeezed into a 1-inch segment of the radius extending from the center of the platter.
    Areal density (bits/in2). The product of the recording density and the track density.

**Disk Operation**
7. Disks read and write bits stored on the magnetic surface using a read/write head connected to the end of an actuator arm
8. the arm back and forth along its radial axis, the drive can position the head over any track on the surface.
9. This mechanical motion is known as a seek. Once the head is positioned over the desired track, then, as each bit on the track passes underneath, the head can either sense the value of the bit (read the bit) or alter the value of the bit (write the bit).
10. Disks with multiple platters have a separate read/write head for each surface
11. Disks with multiple platters have a separate read/write head for each surface
12. The access time for a sector has three main components: seek time, rotational latency, and transfer time:
    * seek time: To read the contents of some target sector, the arm first positions the head over the track that contains the target sector. The time required to move the arm is called the seek time.
    * Rotational latency: Once the head is in position over the track, the drive waits for the first bit of the target sector to pass under the head.
    * Transfer time: When the first bit of the target sector is under the head, the drive can begin to read or write the contents of the sector.
13. We can estimate the average time to access the contents of a disk sector as the sum of the average seek time, the average rotational latency, and the average transfer time.
14. This example illustrates some important points:
    * The time to access the 512 bytes in a disk sector is dominated by the seek time and the rotational latency. Accessing the first byte in the sector takes a long time, but the remaining bytes are essentially free.
    * Since the seek time and rotational latency are roughly the same, twice the seek time is a simple and reasonable rule for estimating disk access time.
    * The access time for a 64-bit word stored in SRAM is roughly 4 ns, and 60 ns for DRAM. Thus, the time to read a 512-byte sector-size block from memory is roughly 256 ns for SRAM and 4,000 ns for DRAM. The disk access time, roughly 10 ms, is about 40,000 times greater than SRAM, and about 2,500 times greater than DRAM.

**Logical Disk Blocks**
16. To hide this complexity from the operating system, modern disks present a simpler view of their geometry as a sequence of B sector-size logical blocks, numbered 0, 1, . . . , B − 1. A small hardware/firmware device in the disk package, called the disk controller, maintains the mapping between logical block numbers and actual (physical) disk sectors.

**Connecting I/O Devices**
17. Input/output (I/O) devices such as graphics cards, monitors, mice, keyboards, and disks are connected to the CPU and main memory using an I/O bus.
18. I/O buses are designed to be independent of the underlying CPU.
19, Although the I/O bus is slower than the system and memory buses, it can accommodate a wide variety of third-party I/O devices.
    * Universal Serial Bus (USB) controller
    * graphics card (or adapter)
    * host bus adapter that connects one or more disks to the I/O bus using a communication protocol defined by a particular host bus interface
20. Additional devices such as network adapters can be attached to the I/O bus by plugging the adapter into empty expansion slots on the motherboard that provide a direct electrical connection to the bus.


### **Accessing Disks**
1. An SSD package plugs into a stan- dard disk slot on the I/O bus (typically USB or SATA) and behaves like any other disk, processing requests from the CPU to read and write logical disk blocks.
2. An SSD package consists of one or more flash memory chips, which replace the me- chanical drive in a conventional rotating disk, and a flash translation layer, which is a hardware/firmware device that plays the same role as a disk controller, trans- lating requests for logical blocks into accesses of the underlying physical device.
3. **Notice that reading from SSDs is faster than writing.**
4. The difference between random reading and writing performance is caused by a fundamental property of the underlying flash memory.


































