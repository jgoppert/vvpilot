# vvpilot

vvpilot is a barebones autopilot that is verified with the cbmc model checker. It is POSIX and MAVLink compatible. The intended platform is the pixhawk autopilot.

## Install Dependencies

The latest CBMC is required for model checking.

### Ubuntu

```bash
sudo apt-get install cmake
make cbmc-ubuntu-install
```

## Build

The cmake build for both model checking and regular executables can be automatically started and with the command

```bash
make
```

This creates two directories, one is build (standard build), and the other is build-mc (using the cbmc goto compiler).

## Test

To run all of the tests for model checking and the regular build run:
```back
make test-all
```
