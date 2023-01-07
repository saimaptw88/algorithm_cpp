## Overviews

- Project to study "algorithm and data structures"
- Code by C++

## Script
### Build image
- `docker-compose build`

### Start container
- `docker-compose up -d`

### Build source
- `docker-compose exec dev cmake ..`
- `docker-compose exec dev cmake --build .` or `docker-compose dev make`

### Execute source
- `docker-compose exec dev src/my_app`

### Unit test
- `docker-compose exec dev src/ch05_test`
