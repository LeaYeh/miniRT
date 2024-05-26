docker build --build-arg USER=$USER -t develop-env .
echo "USER=$(whoami)" > .env
docker-compose up --build -d run-container
