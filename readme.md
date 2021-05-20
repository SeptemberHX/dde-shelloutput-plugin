# dde-shelloutput-plugin

Run shell and show results on your dock or panel on Deepin V20

## Config

Put the content below in file `~/.config/dde-shelloutput/dde-shelloutput.conf`, and restart dde-dock

```ini
[config]
fontColor=#FFFFFF
width=250

[shell]
test\command=date
test\interval=1
test\intervalType=0
test\name=test
test\regExp=
```

* `[shell]`: the group holds all your shell config
* `test`: the config about the shell config `test` (the same as the name)
* `test\interval`: execution repeat interval, integer
* `test\intervalType`: interval unit, 0 is second, 1 is minute, 2 is hour
* `test\regExp`: output regexp. not work now
* `test\command`: the command you want to run repeatly
* `test\name`: shell config name
