# Coldy

Fast, small, and endlessly tweakable console shell written entirely in C.

## RoadMap
- [x] Exit / Echo / Clear
- [x] Customizable Prompt
- [x] read(cat) / append / write / ls
- [ ] currdir / alias
- [ ] re-directions (echo "test" > echo)
- [ ] variables

## Config

Coldy's default config path is `~/.coldy.cfg`.

| Flag  |   Usage                  | Example                                               |
|-------|--------------------------|-------------------------------------------------------|
|PROMPT | Set custom input prompt. | "PROMPT=%U@%H+%P+>+" results in `vxid-dev@VxidDev ~ > `|

## Custom Prompt
Coldy's prompt is built using *templates*.

| Template | What it does               |
|----------|----------------------------|
| %U       | Adds username to prompt    |
| %H       | Adds hostname to prompt    |
| %P       | Adds current path to prompt|

## Commands

| Command | Usage                |
|---------|----------------------|
| echo    | `echo <text>`        |
| exit    | exit                 |
| clear   | clear                |
| list    | `list <dir>`         |
| read    | `read <file>`        |  
| write   | `write <file> <text>`|
| append  | `append <file> <text>`|
| changedir| `changedir <path>`  |
| Alias   | `alias test=echo+hello+world`|
| Currdir | `currdir`                    |

## License 
### GPL 3.0
