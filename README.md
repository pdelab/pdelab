

1. Insde the Docker folder run
    ```
    docker build -t pdelab .
    ```
2. Run
   ```
   docker run -ti  -p 8888:8888 pdelab
   ```
3. Run
    ```
    jupyter lab --ip 0.0.0.0
    ```
4. Then in your browser got to *http://localhost:8888/?token=ADD_TOKIEN_HERE*