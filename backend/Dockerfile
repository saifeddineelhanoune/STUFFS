#BACKEND DOCKER FILE

FROM node:18-alpine
WORKDIR /usr/src/app

COPY ./package.json ./package-lock.json ./
RUN npm install

COPY ./src ./src
COPY ./.env ./.env

EXPOSE 5000
CMD [ "npm", "start" ]