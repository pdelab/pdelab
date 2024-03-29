# PDE Lab

Docker image with jupyter lab and fenics installed. 

## To build and run the Docker image

There are two options **\<tag>=base** (without PyEAFE) or **\<tag>=pyeafe**

1. Download the image from dockerhub
   ```
   docker pull thepdelab/pdelab:<tag>
   ``` 
2. Run
   ```
   docker run -ti  -p 8888:8888 thepdelab/pdelab:<tag>
   ```
   if you need to share a folder:
   ```
   docker run -ti -p 8888:8888 -v <local-foder>:<docker-folder> thepdelab/pdelab:<tag>
   ```
3. Run
    ```
    jupyter lab --ip 0.0.0.0 --allow-root
    ```
4. Then in your browser got to *http://localhost:8888/?token=ADD_TOKIEN_HERE*

## Locally

If you want to run the docker image from the git repository, you can clone it and then run:
```
docker build -t pdelab dockerfiles/base
```