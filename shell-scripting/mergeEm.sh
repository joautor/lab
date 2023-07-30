if [ -e "syslog_merged.log" ]; then
    rm syslog_merged.log
fi

for NUM in $*
do
    cat /tmp/pytest-of-root/pytest-${NUM}/logs/rumag/tests/dedicated/5g/cpri_tdd/test_ok_configure_tdd_switching_timing.py/test_configure_tdd_switching_timing/syslog >> syslog_merged.log
done

