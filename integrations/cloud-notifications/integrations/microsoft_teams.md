<!--startmeta
custom_edit_url: "https://github.com/netdata/netdata/edit/master/integrations/cloud-notifications/integrations/microsoft_teams.md"
meta_yaml: "https://github.com/netdata/netdata/edit/master/integrations/cloud-notifications/metadata.yaml"
sidebar_label: "Microsoft Teams"
learn_status: "Published"
learn_rel_path: "Alerts & Notifications/Notifications/Centralized Cloud Notifications"
message: "DO NOT EDIT THIS FILE DIRECTLY, IT IS GENERATED BY THE NOTIFICATION'S metadata.yaml FILE"
endmeta-->

# Microsoft Teams

<img src="https://netdata.cloud/img/teams.svg" width="150"/>

<img src="https://img.shields.io/badge/maintained%20by-Netdata-%2300ab44" />

## Setup

### Prerequisites

- A Netdata Cloud account
- Access to the Space as an **Admin**
- The Space needs to be on a paid plan
- A [Microsoft Teams Essentials subscription](https://www.microsoft.com/en-sg/microsoft-teams/essentials) or higher. Note that this is a **paid** feature

### Microsoft Teams Configuration

1. Navigate to the desired Microsoft Teams channel and hover over the channel name. Click the three dots icon that appears
2. Select "Workflows" from the options, then choose "Post to a channel when a webhook request is received"
3. **Configure Workflow Details**
    - Give your workflow a name, such as "Netdata Alerts"
    - Select the target team and channel where you will receive notifications
    - Click "Add workflow"
4. Once the workflow is created, you will receive a unique Workflow Webhook URL, copy it, in order to add it to your integration configuration in the Netdata Cloud UI

### Netdata Configuration

1. Click on the **Space settings** cog (located above your profile icon)
2. Click on the **Alerts & Notifications** tab
3. Click on the **+ Add configuration** button
4. Add the Microsoft Teams Integration
5. A modal will be presented to you to enter the required details to enable the integration:
    - **Notification settings**
      - Configuration name (optional): A name for your configuration in order to easily refer to it
      - Rooms: A list of Rooms for which you want to be notified
      - Notifications: The notifications which you want to be notified
    - **Integration configuration**
      - Microsoft Teams Incoming Webhook URL: The Incoming Webhook URL that you copied earlier.

