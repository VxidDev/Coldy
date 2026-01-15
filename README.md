# Coldy

Fast, small, and endlessly tweakable console shell written entirely in C.

## RoadMap
- [x] Exit / Echo / Clear
- [x] Customizable Prompt
- [ ] read(cat) / append / write / ls

## Config

Coldy's default config path is `~/.coldy.cfg`.

| Flag  |   Usage                  | Example                                               |
|-------|--------------------------|-------------------------------------------------------|
|PROMPT | Set custom input prompt. | "PROMPT=%U@%H+>+" results in `vxid-dev@VxidDev > `|

## Custom Prompt
Coldy's prompt is built using *templates*.

| Template | What it does               |
|----------|----------------------------|
| %U       | Adds username to prompt    |
| %H       | Adds hostname to prompt    |

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

## License 
### GPL 3.0
