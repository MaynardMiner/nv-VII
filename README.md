# nv-VII

nv-VII is a simple nvml api script written in C, which is meant to be used instead of nvidia-smi to get fan speed and temperature for RTX series cards, which is currently not working.

to use-

Extract latest release.

run:

``./VII-smi``

sample output for 8 card nvidia GPU setup:

```
0 fan speed=80
0 temperature=34
1 fan speed=80
1 temperature=30
2 fan speed=80
2 temperature=34
3 fan speed=80
3 temperature=27
4 fan speed=80
4 temperature=32
5 fan speed=80
5 temperature=28
6 fan speed=80
6 temperature=30
7 fan speed=80
7 temperature=28
8 fan speed=80
8 temperature=26
```
**To Compile**

-Download latest Cuda Toolkit
-Edit make file with proper tool kit and lib directories.

run 

``make``
