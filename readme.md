# dde-shelloutput-plugin

Run shell and show results on your dock or panel on Deepin V20

## Config

Put the content below in file `~/.config/dde-shelloutput/dde-shelloutput.conf`, and restart dde-dock

```ini
[config]
fontColor=#FFFFFF
width=250
autoWidth=true

[shell]
test\command=date
test\interval=1
test\intervalType=0
test\name=test
test\regExp=\\d{2}:\\d{2}:\\d{2}
```

* `[shell]`: the group holds all your shell config
* `autoWidth`: auto set the width according to the width of the output
* `test`: the config about the shell config `test` (the same as the name)
* `test\interval`: execution repeat interval, integer
* `test\intervalType`: interval unit, 0 is second, 1 is minute, 2 is hour
* `test\regExp`: output regexp. Use \\ for \, like `\\b` instead of `\b`
* `test\command`: the command you want to run repeatly
* `test\name`: shell config name
