# PDE Lab

Docker image with jupyter lab and fenics installed. 

## To build and run the Docker image

1. Download the image from dockerhub
   ```
   docker pull thepnpsolver/pdelab:stable
   ``` 
2. Run
   ```
   docker run -ti  -p 8888:8888 pdelab
   ```
   if you need to share a folder:
   ```
   docker run -ti -p 8888:8888 -v <local-foder>:<docker-folder> pdelab
   ```
3. Run
    ```
    jupyter lab --ip 0.0.0.0 --allow-root
    ```
4. Then in your browser got to *http://localhost:8888/?token=ADD_TOKIEN_HERE*

## Locally

If you want to run the docker image from the git repository, you can clone it and then run:
```
docker build -t pdelab dockerfiles/stable/
```