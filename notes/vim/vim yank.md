## Enable system clipboard integration

Add this to your `vimrc`:

`set clipboard=unnamedplus`

### What this does:

- It tells Vim to use the system clipboard (`+`) for all yank/delete/put operations by default.
- So `yy`, `dd`, and `p` will all interact with the system clipboard — no need to prefix with `"+`.