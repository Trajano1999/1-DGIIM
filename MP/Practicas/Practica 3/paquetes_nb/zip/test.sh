#!/bin/bash

unzip practica3.zip
make
dist/Debug/GNU-Linux/* < data/paquete.dat
