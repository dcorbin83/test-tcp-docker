FROM debian:10 as build-env

RUN apt-get update && apt-get install -y libcurl4

#####################################

FROM gcr.io/distroless/cc

COPY --from=build-env /usr/lib/x86_64-linux-gnu/* /usr/lib/x86_64-linux-gnu/

COPY --from=build-env /lib/x86_64-linux-gnu/* /lib/x86_64-linux-gnu/
