// Copyright 2017-2018 The NATS Authors
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
// http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
#include <nats/nats.h>

int main(int argc, char **argv)
{
    natsConnection      *conn = NULL;
    natsMsg             *msg  = NULL;
    natsStatus          s;

    printf("Publishes a message on subject 'foo'\n");

    // Creates a connection to the default NATS URL
    s = natsConnection_ConnectTo(&conn, NATS_DEFAULT_URL);
    if (s == NATS_OK)
    {
        const char data[] = {104, 101, 108, 108, 111, 33};

        // Creates a message for subject "foo", no reply, and
        // with the given payload.
        s = natsMsg_Create(&msg, "foo", NULL, data, sizeof(data));
    }
    if (s == NATS_OK)
    {
        // Publishes the message on subject "foo".
        s = natsConnection_PublishMsg(conn, msg);
    }

    // Anything that is created need to be destroyed
    natsMsg_Destroy(msg);
    natsConnection_Destroy(conn);

    // If there was an error, print a stack trace and exit
    if (s != NATS_OK)
    {
        nats_PrintLastErrorStack(stderr);
        exit(2);
    }

    return 0;
}

