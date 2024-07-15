#!/bin/bash

python /rtyolo/predict_api.py --device cpu &

sleep 5

python /rtyolo/myclient.py $2

