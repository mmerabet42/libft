# Libft

**libft** is a library of C functions.

It is the very first project in the Ecole 42 cursus. The library might and is supposed to grow thoughout my progress. And because this library is about reinventing the wheel we make sure of reinventing it only once, and using that same wheel for all of our projects.

## Installation

```bash
$> git clone https://github.com/mmerabet42/libft.git libft
$> cd libft
$> make
```

The `make` command will generate a `libft.a` file that should be used to compile your projects

## Sublibraries

The **libft** libray is split into sublibraries for a better genericity.
Each of these sublibraries has his own include path which is in the 'include' directory.
But you can include `libft.h` to include them all.

| Name | Documentation |
| --- | --- |
| `ft_printf.h` |  https://github.com/mmerabet42/ft_printf |
| `ft_regex.h` | https://github.com/mmerabet42/ft_regex |
| `ft_list.h` | |
| `ft_btree.h` | |
| `ft_io.h` | |
| `ft_event.h` | |
| `ft_math.h` | |
| `ft_mem.h` | |
| `ft_str.h` | |
| `ft_types.h` | |
| `get_next_line.h` | |
