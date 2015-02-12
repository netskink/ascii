# ascii
This is sample code given to me by Steve Baker for working iso8859

This is Steve's note which I'm putting here simply for future reference
and acknowledgement of where it came from. I appreciate Steve's help with 
my problem immensely.

Sorry for taking so long to get back to you.  I've always used the "fixed"
font-family with the iso8859 registry.  As long as alternate charset for ascii
codes 109 (L bend), 113 (-), 116 (|-) and 120 (|) are defined.  I've noticed
that most of these charsets are missing the first three of the above for some
reason (but usually none of the other characters, just the three that tree
needs.)  No idea why.

  You can download this:
  > wget http://mama.indstate.edu/users/ice/progs/ascii.c
  > gcc -O -o ascii ascii.c
  > ascii -a

  That will print the alternate character set characters, and you can see for
yourself the alternate character set mappings for ascii 96-126.

