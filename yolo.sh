#!/bin/bash

python /rtyolo/predict_api.py --device cpu &

python /rtyolo/myclient.py $1

