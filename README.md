# leak

An A/UX driver to peek into structs you shouldn't.  If A/UX were remotely secure at this point this would count as a walking security hole.

All the hard work was done in SolraBizna's repository, here: https://github.com/SolraBizna/testc

As usual, I am unskilfully and dodgily balanced on the shoulders of giants.  Etc.

`make install` should install it, then do `newconfig`.

You will need to manually add the invocation of the init script to the bottom of /etc/startup.  I don't know why, and it hasn't annoyed me enough yet to work out how to fix it.