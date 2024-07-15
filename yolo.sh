#!/bin/bash

python /rtyolo/predict_api.py --device cpu &

sleep 10

python /rtyolo/myclient.py $2

