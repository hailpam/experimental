experimental
============

Collection of C++ Helpers
==============================
C++ helpers developed incrementally to solve concrete needs/puzzles.

1. HTTP Scraper: C++ Class: it scrapes the time from www.timeanddate.com (the provided hyperling was not working).

2. File Reader: C++ Class: it takes in input the file stored in data/, then it tokenizes and provides methods list in normal and reverse order the tokens.

3. N-dimensional Dot Product: C++ Class: it takes in input 2 n-dimensional array and calculates parallely (using POSIX Threads) the Dot Product.


How to Start the Test Programs
==============================

From the root directory:

1. Http Scraper
```
	$ bin/bin/test_http_scraper 
	[main] scraping UTC time
	[main] provider www.timeanddate.com
	[main] scraped { dimanche 13 avril 2014, 18 h 01 m 14 }
```

2. File Reader
```
	$ bin/test_file_reader 
	[main] file read outcome [1]
	[FileReader][printContent] content <This is a simple test. I am doing my best, of course! Author: Paolo Maresca <plo.maresca@gmail.com> >
	[FileReader][reverseListTokens] token <<plomaresca@gmailcom>>
	[FileReader][reverseListTokens] token <Maresca>
	[FileReader][reverseListTokens] token <Paolo>
	[FileReader][reverseListTokens] token <Author>
	[FileReader][reverseListTokens] token <course>
	[FileReader][reverseListTokens] token <of>
	[FileReader][reverseListTokens] token <best>
	[FileReader][reverseListTokens] token <my>
	[FileReader][reverseListTokens] token <doing>
	[FileReader][reverseListTokens] token <am>
	[FileReader][reverseListTokens] token <I>
	[FileReader][reverseListTokens] token <test>
	[FileReader][reverseListTokens] token <simple>
	[FileReader][reverseListTokens] token <a>
	[FileReader][reverseListTokens] token <is>
	[FileReader][reverseListTokens] token <This>
```
3. N-dimensional Dot Product
```
	$ bin/test_nd_product 
	[main] vector A (4, 2, 7, 5, 1, 3, 6, 2, 8, 9)
	[main] vector B (3, 5, 2, 1, 7, 6, 9, 2, 1, 3)
	[main] sum dot product [159]
```

How to compile the source code
==============================

From the root directory, making use of the Makefile:

1. Clean previous build
```
	$ make clean
```

2. Creates a new build
```
	$ make
```

Compatibility
=============

The build process has been tested only on Linux Fedora:

1. Uname
```
	$ uname -a
	Linux PM-PC.home 3.6.10-4.fc18.x86_64 #1 SMP Tue Dec 11 18:01:27 UTC 2012 x86_64 x86_64 x86_64 GNU/Linux
```

2. GCC
```
	$ gcc -v
	Using built-in specs.
	COLLECT_GCC=gcc
	COLLECT_LTO_WRAPPER=/usr/libexec/gcc/x86_64-redhat-linux/4.7.2/lto-wrapper
	Target: x86_64-redhat-linux
	Configured with: ../configure --prefix=/usr --mandir=/usr/share/man --infodir=/usr/share/info --with-bugurl=http://bugzilla.redhat.com/bugzilla --enable-bootstrap --enable-shared --enable-threads=posix --enable-checking=release --disable-build-with-cxx --disable-build-poststage1-with-cxx --with-system-zlib --enable-__cxa_atexit --disable-libunwind-exceptions --enable-gnu-unique-object --enable-linker-build-id --with-linker-hash-style=gnu --enable-languages=c,c++,objc,obj-c++,java,fortran,ada,go,lto --enable-plugin --enable-initfini-array --enable-java-awt=gtk --disable-dssi --with-java-home=/usr/lib/jvm/java-1.5.0-gcj-1.5.0.0/jre --enable-libgcj-multifile --enable-java-maintainer-mode --with-ecj-jar=/usr/share/java/eclipse-ecj.jar --disable-libjava-multilib --with-ppl --with-cloog --with-tune=generic --with-arch_32=i686 --build=x86_64-redhat-linux
	Thread model: posix
	gcc version 4.7.2 20121109 (Red Hat 4.7.2-8) (GCC)
```

Limitations/Improvements
========================

Some improvements might be done, in the source code some TODO have been left for future reworks.

