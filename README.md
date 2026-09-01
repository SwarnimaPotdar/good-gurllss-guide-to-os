🎀 Good Gurllss Guide to OS
(because apparently I decided building an operating system would be a good idea) ehehehe....

Welcome to Good Gurllss Guide to OS, my journey of figuring out how operating systems actually work by building one myself.
The project is called GirlieOS.
The OS is called SLAY.
And the shell is called PinkShell.
Yes, I know the names are ridiculous.
No, I'm not changing them. 💅
so... what am I doing?
I've used computers for basically my entire life without ever really thinking about what happens underneath everything.
You click an app.
It opens.
You type something.
The computer does something.
Cool.
But what actually makes all of that happen?
So instead of just reading about operating systems, I decided to learn by building one.
From scratch.
Or as close to "from scratch" as a reasonable human being can get. 😭🤧
This repository is going to contain both the actual OS and everything I learn while building it.
🎀 the names
GirlieOS:
The overall project and community.
SLAY:
The actual operating system.
PinkShell:
The command-line shell that lives inside SLAY.
And yes, eventually I want commands that sound like this:
$ slay

✨ you slayy gurlll ✨
because if I'm going to spend months staring at kernel code, I deserve this.
🩷 what I want to learn
This isn't just about making something pink.
I want to understand what's happening underneath the software I normally build.
So we're going into:
-> computer architecture
-> booting
-> C
-> x86-64 assembly
-> kernels
-> memory management
-> interrupts
-> processes
-> scheduling
-> system calls
-> filesystems
-> drivers
-> networking
-> security
-> shells
-> graphics
-> GUI development
Basically:
how does a computer actually computes?
🩷 current setup
I'm developing on an Apple Silicon Mac, but SLAY is initially targeting x86_64.
So the current setup is:
Mac (ARM64)
     │
     ├── VS Code
     ├── Git
     └── x86_64 cross-compiler
              │
              ▼
           SLAY
              │
              ▼
            QEMU
QEMU lets me experiment with SLAY without touching the actual operating system on my Mac.
Which is probably good considering I have absolutely no intention of accidentally deleting macOS. 💀
🚧 where we are right now
Project setup.
Nothing impressive yet.
Just a repository, a compiler, and an unreasonable amount of ambition.
The first real milestone is simple:
Get SLAY to boot.
Then we'll figure out what happens next.
🗺️ the very ambitious plan
Boot -> Kernel -> Display -> Keyboard -> Memory -> Processes -> Filesystem -> Userspace -> PinkShell -> Networking -> GUI -> Apps -> SLAY 🎀

There will probably be approximately zillion things that go wrong in between.
That's kind of the point.
💗 why this repository exists
This is partly a project and partly a learning journal.
I'm going to document the things I learn, the things I break, the things I don't understand, and hopefully the things I eventually figure out.
If you're also curious about operating systems, systems programming, or just want to watch someone attempt something slightly ridiculous:
welcome.
Current status
🎀 GirlieOS: alive (in thoughts but still counts)
💻 SLAY: not booting yet
💅 PinkShell: currently just a dream
🧠 Me: figuring it out 🤷‍♀️

Day 3: We booted her successfully🩷
