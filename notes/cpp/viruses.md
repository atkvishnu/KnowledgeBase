Legal Info

Here's a reference to how the US courts generally view code:

[Who's Responsible? - Computer Crime Laws](http://www.pbs.org/wgbh/pages/frontline/shows/hackers/blame/crimelaws.html "www.pbs.org")

"The Computer Fraud and Abuse Act (CFAA) [18 U.S.C. Section 1030] makes it illegal for anyone to distribute computer code or place it in the stream of commerce if they intend to cause either damage or economic loss"

Canada takes a similar stance, with it's legislation specifically making clear that you can install whatever you like on your own system:

[Canada’s Anti-Spam Legislation Requirements for Installing Computer Programs](http://crtc.gc.ca/eng/internet/install.htm "crtc.gc.ca")

This tends to be the standard view, but other countries may be different so it is your responsibility to double check the laws in your area. Some countries have been known to execute programmers even for the mere impression that they programmed was used by someone else in some way that might have damaged a system even if it didn't happen in that country, so if you plan to visit one of these countries, take care. (of course, this isn't just a statement about viral code, but it's worth making clear since I am otherwise asserting the legality of programming)

[Canadian resident sentenced to death for writing a computer program](https://nakedsecurity.sophos.com/2012/01/24/canadian-resident-sentenced-to-death-for-writing-a-computer-program/ "nakedsecurity.sophos.com")

The Virus

With this cleared up, there are places you can go to learn, but first you need to understand that even if you work on this inside a virtual machine there are cases that they can escape, so you will want to use a computer with non-critcal information that can run a virtual machine and treat that VM as a layer of protection rather than an invincible shield.

Here's an article discussing this problem:

[‘VM-aware’ viruses on the rise](http://www.computerweekly.com/news/2240169662/VM-aware-viruses-on-the-rise "www.computerweekly.com")

If you are studying someone else's virus to develop counter measures, be aware that it might detect that it is inside a virtual machine even if it can't escape and will change it's behavior accordingly. If this is the case you will need to study on a clean machine. To save time you can clone the hard drive and swap it out when done testing.

If you want to study how a virus - or any program - is able to do this here is a good resource: (this is of course application specific, but it gives you an idea)

[Detect if your program is running inside a Virtual Machine](http://www.codeproject.com/Articles/9823/Detect-if-your-program-is-running-inside-a-Virtual "www.codeproject.com")

Beyond the tutorials themselves, and a safe environment you need to run them, there are also different target systems with their own behavior. Contrary to popular belief, a virus can actually infect Unix, but it is written differently from a Windows virus.

Here's an interesting articles on how a virus works in Unix:

[White Paper: Viruses in a Unix world](http://www.computerweekly.com/feature/White-Paper-Viruses-in-a-Unix-world "www.computerweekly.com")

Remember, it's legal to infect your own systems, but if you program a virus that even accidentally gets into the wild you can be held criminally responsible for any damages. Take care!

[Virus code tutorial](http://hackersplace-parth.blogspot.com/p/virus-code-tutorial.html "hackersplace-parth.blogspot.com")

[Introduction to Viral Programming](http://vxheaven.org/lib/static/vdat/mpgui001.htm "vxheaven.org")

[Virus Writing - HackersOnlineClub](http://hackersonlineclub.com/virus-writing/ "hackersonlineclub.com")

[How to Create a Computer Virus?](http://www.gohacking.com/create-computer-virus/ "www.gohacking.com")

As you can see from some of the above examples, a virus can do many little things. One snippet just makes an endless stream of notepads on an infinite loop until the system crashes, which is functionally no different from using an infinite loop in a php script.

The Trojan

There are also other types of programs, like Trojan Horses, which are not really the same thing as a virus, but are good to understand. Here's a PDF on the differences between a virus and a trojan horse from a university:

[http://www.cs.sjsu.edu/~stamp/CS265/projects/Spr04/section2/papers/Agrawal.doc](http://www.cs.sjsu.edu/~stamp/CS265/projects/Spr04/section2/papers/Agrawal.doc "www.cs.sjsu.edu")

Some links to look into:

[How to Make a Trojan Horse](http://www.gohacking.com/make-trojan-horse/ "www.gohacking.com")

[http://flylib.com/books/en/3.448.1.53/1/](http://flylib.com/books/en/3.448.1.53/1/ "flylib.com")

The Anti Virus

Of course, the real benefit of studying a virus is to learn how they work and to (hopefully) be a force for good and program new approaches to virus removal.

[Building an Anti-Virus Engine](http://www.symantec.com/connect/articles/building-anti-virus-engine "www.symantec.com")

[Making an antivirus engine : the guidelines](http://www.adlice.com/making-an-antivirus-engine-the-guidelines/ "www.adlice.com")

[How To Make Antivirus Using C++ Programming Language](http://freaksense.com/how-to-make-antivirus-using-c-programming-language/ "freaksense.com")

[How hard is it to develop an antivirus software?](https://www.quora.com/How-hard-is-it-to-develop-an-antivirus-software "www.quora.com")