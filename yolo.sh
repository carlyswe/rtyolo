#!/bin/bash


#no longer need this once seperated client & server

python /rtyolo/predict_api.py --device cpu &

python /rtyolo/myclient.py $2

