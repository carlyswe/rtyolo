#!/bin/bash

python predict_api.py --device cpu &

python myclient.py 

