FROM python:3.8

RUN <<EOF
    cd /
    git clone https://github.com/carlyswe/rtyolo 
    cd rtyolo
    pip install -r requirements.txt
    apt-get update && apt-get install ffmpeg libsm6 libxext6 -y
    
    g++ setprio.cpp -o setprio

EOF

ENTRYPOINT ["/rtyolo/setprio"]
CMD ["SCHED_FIFO", "10", "2"]
