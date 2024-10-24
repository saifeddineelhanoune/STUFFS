#FRONT-END DOCKER FILE

#Step1: Build the next.js app
FROM node:18 AS builder
WORKDIR /app

COPY ./package.json ./package-lock.json ./
RUN npm install

COPY . .
RUN npm run build

#Step2: Serve the app using Next.js
FROM node:18-alpine AS runner
WORKDIR /app

COPY --from=builder /app/.next ./.next
COPY --from=builder /app/node_modules ./node_modules
COPY --from=builder /app/package.json ./package.json

EXPOSE 3000
CMD [ "npm", "run", "start" ]
