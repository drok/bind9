set args -c /tmp/named/config/named.conf -g
# b dns_zone_create if zone==0xb36b64f0
# b dns_zonemgr_managezone if strcmp(zone->masterfile,"tmpublic.net.Public.zone") == 0
# b  zone.c:4643 if zone->masterfile && strcmp(zone->masterfile,"tmpublic.net.Public.zone") == 0
b  zone.c:14663 if zone==0xb36b64f0
b zone.c:14663 if zone->masterfile && strcmp(zone->masterfile,"tmpublic.net.Public.zone") == 0
b zoneconf.c:1332
b zone.c:16816
b zone.c:14663
run
thread apply all bt
